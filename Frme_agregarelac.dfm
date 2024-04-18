object Frame_agregarelac: TFrame_agregarelac
  Left = 0
  Top = 0
  Width = 610
  Height = 319
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 9
    Top = 2
    Width = 592
    Height = 231
    Caption = 'Relacionar Tablas:'
    TabOrder = 0
    object Label1: TLabel
      Left = 13
      Top = 22
      Width = 98
      Height = 13
      Caption = 'Tabla Seleccionada:'
    end
    object lbl_tabla: TLabel
      Left = 116
      Top = 22
      Width = 29
      Height = 13
      Caption = 'tabla'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold, fsUnderline]
      ParentFont = False
    end
    object GroupBox3: TGroupBox
      Left = 16
      Top = 40
      Width = 157
      Height = 185
      Caption = 'Lista de Campos'
      TabOrder = 0
      object ListBox1: TListBox
        Left = 11
        Top = 15
        Width = 134
        Height = 163
        ItemHeight = 13
        TabOrder = 0
      end
    end
    object GroupBox4: TGroupBox
      Left = 184
      Top = 40
      Width = 212
      Height = 185
      Caption = 'Tabla Disponibles'
      TabOrder = 1
      object dbgrd_polizas: TdxDBGrid
        Left = 10
        Top = 15
        Width = 190
        Height = 163
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDTABLA'
        SummaryGroups = <
          item
            DefaultGroup = False
            SummaryItems = <
              item
                ColumnName = 'dbgrd_renpolBonif'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_renpolRecar'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_renpolIMPOR'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_renpolNeto'
                SummaryType = cstSum
              end>
            Name = 'dbgrd_renpolSummaryGroup2'
          end>
        SummarySeparator = ', '
        TabOrder = 0
        DataSource = dts_tablas
        Filter.Active = True
        Filter.Criteria = {00000000}
        OptionsBehavior = [edgoAutoSearch, edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseLocate]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        object dbgrd_polizasTABLA: TdxDBGridMaskColumn
          Caption = 'Tabla'
          Width = 136
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TABLA'
        end
        object dbgrd_polizasENDESUSO: TdxDBGridMaskColumn
          Caption = 'En Uso'
          Width = 80
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ENDESUSO'
        end
      end
    end
    object GroupBox5: TGroupBox
      Left = 405
      Top = 40
      Width = 174
      Height = 185
      Caption = 'Lista de Campos'
      TabOrder = 2
      object lista_colum: TListBox
        Left = 10
        Top = 14
        Width = 152
        Height = 163
        ItemHeight = 13
        TabOrder = 0
      end
    end
    object edt_idrel: TEdit
      Left = 416
      Top = 16
      Width = 33
      Height = 21
      TabOrder = 3
      Text = 'edt_idrel'
      Visible = False
    end
    object edt_tablarel: TEdit
      Left = 456
      Top = 16
      Width = 33
      Height = 21
      TabOrder = 4
      Visible = False
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 235
    Width = 593
    Height = 78
    Caption = 'Otros Datos:'
    TabOrder = 1
    object Label5: TLabel
      Left = 8
      Top = 25
      Width = 84
      Height = 13
      Caption = 'Tipo de Relacion:'
    end
    object Label6: TLabel
      Left = 142
      Top = 25
      Width = 56
      Height = 13
      Caption = 'Descipcion:'
    end
    object Label7: TLabel
      Left = 125
      Top = 51
      Width = 74
      Height = 13
      Caption = 'Observaciones:'
    end
    object edt_rela: TEdit
      Left = 94
      Top = 22
      Width = 27
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 0
    end
    object edt_descrip: TEdit
      Left = 201
      Top = 23
      Width = 349
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 1
    end
    object edt_observ: TEdit
      Left = 201
      Top = 48
      Width = 347
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 2
    end
  end
  object qry_tablas: TQuery
    CachedUpdates = True
    ObjectView = True
    AfterScroll = qry_tablasAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from info_car_tablas order by idtabla')
    Left = 308
    Top = 105
  end
  object dts_tablas: TDataSource
    DataSet = qry_tablas
    Left = 275
    Top = 106
  end
  object qry_columns: TQuery
    DatabaseName = 'manvehi'
    Left = 241
    Top = 106
  end
  object qry_tablarel: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from info_car_tablas where idtabla = :IDREL')
    Left = 345
    Top = 104
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDREL'
        ParamType = ptUnknown
      end>
  end
end
