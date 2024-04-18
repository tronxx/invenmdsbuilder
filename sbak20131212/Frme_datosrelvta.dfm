object Frame_datosrelvta: TFrame_datosrelvta
  Left = 0
  Top = 0
  Width = 617
  Height = 496
  TabOrder = 0
  object Panel3: TPanel
    Left = 0
    Top = 205
    Width = 617
    Height = 291
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Splitter1: TSplitter
      Left = 353
      Top = 0
      Width = 3
      Height = 291
      Cursor = crHSplit
    end
    object GroupBox5: TGroupBox
      Left = 356
      Top = 0
      Width = 261
      Height = 291
      Align = alClient
      Caption = 'Existencias'
      TabOrder = 0
      object dxDBGrid1: TdxDBGrid
        Left = 2
        Top = 15
        Width = 257
        Height = 274
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'ALM'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        DataSource = dts_exist
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        object dxDBGrid1Column1: TdxDBGridMaskColumn
          Caption = 'Alm'
          Width = 25
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ALM'
        end
        object dxDBGrid1Column2: TdxDBGridMaskColumn
          Caption = 'Existencia'
          Width = 49
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TOTEXI'
        end
        object dxDBGrid1Column3: TdxDBGridDateColumn
          Caption = 'Fecha'
          Sorted = csUp
          Width = 52
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECHA'
        end
        object dxDBGrid1Column4: TdxDBGridMaskColumn
          Caption = 'T.Comp'
          Width = 49
          BandIndex = 0
          RowIndex = 0
          FieldName = 'COMPROM'
        end
        object dxDBGrid1Column5: TdxDBGridMaskColumn
          Caption = 'Comprometidos En'
          Width = 100
          BandIndex = 0
          RowIndex = 0
          FieldName = 'COMPR'
        end
      end
    end
    object GroupBox4: TGroupBox
      Left = 0
      Top = 0
      Width = 353
      Height = 291
      Align = alLeft
      Caption = 'Re&nglones'
      TabOrder = 1
      TabStop = True
      object dbgrd_rengnes: TdxDBGrid
        Left = 2
        Top = 45
        Width = 349
        Height = 244
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDRELVTAART'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        OnKeyDown = dbgrd_rengnesKeyDown
        DataSource = dts_renentra
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        object dbgrd_rengnesCODIGO: TdxDBGridMaskColumn
          Caption = 'Código'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'CODIGO'
        end
        object dbgrd_rengnesDESCRI: TdxDBGridMaskColumn
          Caption = 'Descripción'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'DESCRI'
        end
        object dbgrd_rengnesSALEDE: TdxDBGridMaskColumn
          Caption = 'Sale De'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'SALEDE'
        end
        object dbgrd_rengnesColumn4: TdxDBGridCurrencyColumn
          Caption = 'Precio.V'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'PRECIOLISTA'
        end
      end
      object Panel1: TPanel
        Left = 2
        Top = 15
        Width = 349
        Height = 30
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 1
        object BitBtn1: TBitBtn
          Left = 17
          Top = 1
          Width = 75
          Height = 25
          Action = primer_artic
          Caption = 'Primero'
          TabOrder = 0
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            000000000000000000000000FF000000FF000000FF000000FF000000FF000000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
            FF000000FF000000FF000000FF000000FF000000FF0000000000000000000000
            000000000000000000000000FF000000FF000000FF000000FF000000FF000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
        object BitBtn2: TBitBtn
          Left = 97
          Top = 1
          Width = 75
          Height = 25
          Action = anter_artic
          Caption = 'Anterior'
          TabOrder = 1
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF0000000000000000000000FF000000FF000000FF000000FF000000FF000000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
            FF000000FF000000FF000000FF000000FF000000FF0000000000FF00FF00FF00
            FF0000000000000000000000FF000000FF000000FF000000FF000000FF000000
            0000000000000000000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
        object BitBtn3: TBitBtn
          Left = 177
          Top = 1
          Width = 75
          Height = 25
          Action = sigte_artic
          Caption = 'Siguiente'
          TabOrder = 2
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
            FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00000000000000
            000000000000000000000000000000000000000000000000FF000000FF000000
            FF000000FF000000FF000000000000000000FF00FF00FF00FF00000000000000
            FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
            FF000000FF000000FF000000FF000000FF000000000000000000000000000000
            000000000000000000000000000000000000000000000000FF000000FF000000
            FF000000FF000000FF000000000000000000FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
            FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
        object BitBtn4: TBitBtn
          Left = 257
          Top = 1
          Width = 75
          Height = 25
          Action = ultimo_artic
          Caption = 'Ultimo'
          TabOrder = 3
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
            FF000000000000000000FF00FF00FF00FF000000000000000000000000000000
            000000000000000000000000000000000000000000000000FF000000FF000000
            FF000000FF000000FF0000000000000000000000000000000000000000000000
            FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
            FF000000FF000000FF000000FF000000FF000000000000000000000000000000
            000000000000000000000000000000000000000000000000FF000000FF000000
            FF000000FF000000FF0000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
            FF000000000000000000FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000}
        end
      end
    end
  end
  object GroupBox6: TGroupBox
    Left = 0
    Top = 0
    Width = 617
    Height = 205
    Align = alTop
    TabOrder = 0
    TabStop = True
    object lbl_folio: TLabel
      Left = 6
      Top = 14
      Width = 37
      Height = 13
      Caption = 'Número'
      FocusControl = edt_nument
    end
    object Label2: TLabel
      Left = 11
      Top = 38
      Width = 32
      Height = 13
      Caption = 'Cliente'
      FocusControl = edt_nombre
    end
    object Label15: TLabel
      Left = 10
      Top = 60
      Width = 33
      Height = 13
      Caption = 'Ciudad'
    end
    object Label7: TLabel
      Left = 15
      Top = 82
      Width = 28
      Height = 13
      Caption = 'Direc:'
      FocusControl = edt_nombre
    end
    object Label9: TLabel
      Left = 237
      Top = 14
      Width = 23
      Height = 13
      Caption = 'Hora'
      FocusControl = edt_nument
    end
    object Label8: TLabel
      Left = 13
      Top = 151
      Width = 33
      Height = 13
      Caption = 'Código'
    end
    object Label10: TLabel
      Left = 2
      Top = 171
      Width = 38
      Height = 13
      Caption = 'Pr. Lista'
    end
    object Label3: TLabel
      Left = 349
      Top = 150
      Width = 46
      Height = 13
      Caption = 'F.Entrega'
      FocusControl = edt_nument
    end
    object Label5: TLabel
      Left = 349
      Top = 62
      Width = 46
      Height = 13
      Caption = 'Vendedor'
    end
    object Label14: TLabel
      Left = 356
      Top = 16
      Width = 40
      Height = 13
      Caption = 'Tipo Vta'
    end
    object Label6: TLabel
      Left = 357
      Top = 104
      Width = 37
      Height = 13
      Caption = 'Entrega'
    end
    object Label11: TLabel
      Left = 347
      Top = 38
      Width = 47
      Height = 13
      Caption = 'Punto Vta'
    end
    object Label16: TLabel
      Left = 351
      Top = 81
      Width = 43
      Height = 13
      Caption = 'Tipo Entr'
    end
    object Label1: TLabel
      Left = 341
      Top = 126
      Width = 57
      Height = 13
      Caption = 'Forma Pago'
    end
    object edt_nument: TdxCurrencyEdit
      Left = 48
      Top = 12
      Width = 50
      TabOrder = 0
      Alignment = taRightJustify
      DecimalPlaces = 0
      DisplayFormat = '0'
      Value = 1
      StoredValues = 1
    end
    object edt_nombre: TdxEdit
      Left = 48
      Top = 34
      Width = 280
      TabOrder = 2
      CharCase = ecUpperCase
      MaxLength = 30
      StoredValues = 2
    end
    object lkcmb_ciudad: TDBLookupComboBox
      Left = 48
      Top = 56
      Width = 280
      Height = 21
      KeyField = 'NUMERO'
      ListField = 'NOMBRE'
      ListSource = dts_ciudad
      TabOrder = 3
    end
    object mmo_direc: TMemo
      Left = 48
      Top = 79
      Width = 280
      Height = 65
      TabOrder = 4
    end
    object edt_codigo: TEdit
      Left = 49
      Top = 146
      Width = 113
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 6
      OnExit = edt_codigoExit
      OnKeyDown = edt_codigoKeyDown
    end
    object btn_nvoren: TBitBtn
      Left = 167
      Top = 167
      Width = 96
      Height = 25
      Caption = 'A&grega.Reng'
      TabOrder = 8
      OnClick = btn_nvorenClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        33333333FF33333333FF333993333333300033377F3333333777333993333333
        300033F77FFF3333377739999993333333333777777F3333333F399999933333
        33003777777333333377333993333333330033377F3333333377333993333333
        3333333773333333333F333333333333330033333333F33333773333333C3333
        330033333337FF3333773333333CC333333333FFFFF77FFF3FF33CCCCCCCCCC3
        993337777777777F77F33CCCCCCCCCC3993337777777777377333333333CC333
        333333333337733333FF3333333C333330003333333733333777333333333333
        3000333333333333377733333333333333333333333333333333}
      NumGlyphs = 2
    end
    object edt_preciolis: TdxCurrencyEdit
      Left = 49
      Top = 168
      Width = 113
      TabOrder = 7
    end
    object date_fentrega: TDateTimePicker
      Left = 400
      Top = 144
      Width = 206
      Height = 21
      CalAlignment = dtaLeft
      Date = 37548.4553024306
      Time = 37548.4553024306
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 14
    end
    object lkcmb_vendedr: TDBLookupComboBox
      Left = 400
      Top = 56
      Width = 60
      Height = 21
      DropDownWidth = 200
      KeyField = 'CODIGO'
      ListField = 'CODIGO; NOMBRE'
      ListSource = dts_vendr
      TabOrder = 10
    end
    object DBEdit3: TDBEdit
      Left = 461
      Top = 56
      Width = 144
      Height = 21
      TabStop = False
      DataField = 'NOMBRE'
      DataSource = dts_vendr
      TabOrder = 17
    end
    object lkcmb_tipocte: TDBLookupComboBox
      Left = 401
      Top = 12
      Width = 60
      Height = 21
      DropDownWidth = 200
      KeyField = 'IDTICTE'
      ListField = 'ticte; DESCRI'
      ListSource = dts_tiposctes
      TabOrder = 5
    end
    object DBEdit6: TDBEdit
      Left = 461
      Top = 12
      Width = 144
      Height = 21
      TabStop = False
      DataField = 'DESCRI'
      DataSource = dts_tiposctes
      TabOrder = 18
    end
    object lkcmb_entrega: TDBLookupComboBox
      Left = 401
      Top = 100
      Width = 60
      Height = 21
      DropDownWidth = 200
      KeyField = 'CLAVE'
      ListField = 'Clave; NOMBRE'
      ListSource = dts_chofer
      TabOrder = 12
    end
    object DBEdit1: TDBEdit
      Left = 461
      Top = 100
      Width = 144
      Height = 21
      TabStop = False
      DataField = 'NOMBRE'
      DataSource = dts_chofer
      TabOrder = 19
    end
    object lkcmb_ptovta: TDBLookupComboBox
      Left = 401
      Top = 34
      Width = 60
      Height = 21
      DropDownWidth = 200
      KeyField = 'CLAVE'
      ListField = 'Clave; NOMBRE'
      ListSource = dts_ptovta
      TabOrder = 9
    end
    object DBEdit4: TDBEdit
      Left = 461
      Top = 34
      Width = 144
      Height = 21
      TabStop = False
      DataField = 'NOMBRE'
      DataSource = dts_ptovta
      TabOrder = 20
    end
    object lkcmb_tipoentr: TDBLookupComboBox
      Left = 401
      Top = 78
      Width = 60
      Height = 21
      DropDownWidth = 200
      KeyField = 'IDTIPOENTREGA'
      ListField = 'CODIGO; DESCRI'
      ListSource = dts_tipoentrega
      TabOrder = 11
    end
    object DBEdit7: TDBEdit
      Left = 461
      Top = 78
      Width = 144
      Height = 21
      TabStop = False
      DataField = 'DESCRI'
      DataSource = dts_tipoentrega
      TabOrder = 21
    end
    object edt_descri: TEdit
      Left = 164
      Top = 146
      Width = 163
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 30
      TabOrder = 16
    end
    object btn_buscarfolio: TButton
      Left = 400
      Top = 168
      Width = 129
      Height = 25
      Caption = '&Buscar Folio'
      TabOrder = 15
      OnClick = btn_buscarfolioClick
    end
    object date_hora: TdxTimeEdit
      Left = 269
      Top = 12
      Width = 60
      TabOrder = 1
      Time = 0.416666666666667
      TimeEditFormat = tfHourMin
      StoredValues = 4
    end
    object lkcmb_tipopago: TDBLookupComboBox
      Left = 401
      Top = 122
      Width = 206
      Height = 21
      DropDownWidth = 200
      KeyField = 'idcrdcon'
      ListField = 'descri'
      ListSource = dts_formapago
      TabOrder = 13
    end
  end
  object qry_tiposctes: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select  idticte, ticte, descri from car_tiposctes where cia = :C' +
        'IA order by ticte')
    Left = 104
    Top = 352
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_tiposctes: TDataSource
    DataSet = qry_tiposctes
    Left = 104
    Top = 381
  end
  object qry_ciudad: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select nombre, numero from poblacs order by nombre')
    Left = 97
    Top = 283
  end
  object dts_ciudad: TDataSource
    DataSet = qry_ciudad
    Left = 97
    Top = 312
  end
  object qry_vendr: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.codigo, a.nombre, b.ptovta, b.zona'
      
        'from vendedor a left outer join inv_vndptovt b on a.codigo = b.c' +
        'odigo'
      'order by a.codigo')
    Left = 129
    Top = 284
  end
  object dts_vendr: TDataSource
    DataSet = qry_vendr
    Left = 129
    Top = 312
  end
  object qry_chofer: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre'
      ' from promotor where status = '#39'A'#39
      'order by clave')
    Left = 161
    Top = 284
  end
  object dts_chofer: TDataSource
    DataSet = qry_chofer
    Left = 161
    Top = 312
  end
  object qry_exist: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select a.codigo, alm, cast('#39#39' as varchar(30)) as compr, count(*)' +
        ' as totexi,'
      'min(fecha) as fecha, sum(0) as comprom'
      
        'from exist a join movart b on a.alm = b.almac and a.codigo = b.c' +
        'odigo and a.cia = b.cia'
      'where a.codigo = :CODIGO'
      'and a.cia = :CIA and b.salio <> '#39'S'#39
      'group by a.codigo, alm, a.codigo')
    UpdateObject = uqry_exist
    Left = 189
    Top = 282
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_exist: TDataSource
    DataSet = qry_exist
    Left = 193
    Top = 312
  end
  object qry_tipoentrega: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select  idtipoentrega, codigo, descri '
      'from inv_tipoentrega '
      'where cia = :CIA'
      'order by codigo'
      '')
    Left = 240
    Top = 280
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_tipoentrega: TDataSource
    DataSet = qry_tipoentrega
    Left = 240
    Top = 309
  end
  object qry_ptovta: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre from ptovta where cia = :CIA order by clave')
    Left = 293
    Top = 355
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_ptovta: TDataSource
    DataSet = qry_ptovta
    Left = 293
    Top = 384
  end
  object uqry_renentra: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_relvtaart'
      'set'
      '  IDRELVTAART = :IDRELVTAART,'
      '  IDRELVTAS = :IDRELVTAS,'
      '  IDART = :IDART,'
      '  SALEDE = :SALEDE,'
      '  CONSE = :CONSE,'
      '  IDCODIGO = :IDCODIGO,'
      '  IDDESCRI = :IDDESCRI,'
      '  IDRELTRANSF = :IDRELTRANSF,'
      '  IDPOLRELVTA = :IDPOLRELVTA,'
      '  PRECIOLISTA = :PRECIOLISTA'
      'where'
      '  IDRELVTAART = :OLD_IDRELVTAART')
    InsertSQL.Strings = (
      'insert into inv_relvtaart'
      
        '  (IDRELVTAART, IDRELVTAS, IDART, SALEDE, CONSE, IDCODIGO, IDDES' +
        'CRI, '
      'IDRELTRANSF, '
      '   IDPOLRELVTA, PRECIOLISTA)'
      'values'
      
        '  (:IDRELVTAART, :IDRELVTAS, :IDART, :SALEDE, :CONSE, :IDCODIGO,' +
        ' '
      ':IDDESCRI, '
      '   :IDRELTRANSF, :IDPOLRELVTA, :PRECIOLISTA)')
    DeleteSQL.Strings = (
      'delete from inv_relvtaart'
      'where'
      '  IDRELVTAART = :OLD_IDRELVTAART')
    Left = 64
    Top = 285
  end
  object qry_renentra: TQuery
    CachedUpdates = True
    AfterScroll = qry_renentraAfterScroll
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select idrelvtaart, idrelvtas, a.idart, salede, conse, a.idcodig' +
        'o, a.iddescri,'
      'a.idreltransf, a.idpolrelvta, 0 as folio,'
      'cast(b.concepto as varchar(13) ) as codigo, '
      'c.concepto as descri, preciolista'
      'from'
      'inv_relvtaart a '
      'join conceps b on a.idcodigo = b.ncon'
      'join conceps c on a.iddescri = c.ncon'
      'where idrelvtas = :IDRELVTAS'
      'order by conse')
    UpdateObject = uqry_renentra
    Left = 63
    Top = 313
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDRELVTAS'
        ParamType = ptUnknown
      end>
  end
  object dts_renentra: TDataSource
    AutoEdit = False
    DataSet = qry_renentra
    Left = 63
    Top = 342
  end
  object qry_ubica: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select  clave, nombre from almacen where cia = :CIA order by cla' +
        've')
    Left = 272
    Top = 282
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_ubica: TDataSource
    DataSet = qry_ubica
    Left = 272
    Top = 311
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.codigo, a.descri, tipo, costos, coston, piva, precio, b' +
        '.idart'
      
        'from inven a join inv_invhist b on a.codigo = b.codigo and a.cia' +
        ' = b.cia'
      'where a.codigo = :CODIGO and a.cia = :CIA order by a.codigo')
    Left = 143
    Top = 353
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 143
    Top = 382
  end
  object qry_comprometidos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.codigo, b.salede, c.tipocte, count(d.folio) as unids'
      
        'from inv_comprometart  a join inv_relvtaart b on a.idrelvtaart =' +
        ' b.idrelvtaart'
      'join inv_relvtas c on b.idrelvtas = c.idrelvtas'
      
        'join movart d on a.codigo = d.codigo and b.salede = d.almac and ' +
        'a.cia = d.cia'
      'and a.unids = d.folio'
      'where'
      'a.codigo = :CODIGO and a.cia = :CIA'
      
        'and ( d.salio <> '#39'S'#39'  or ( d.salio = '#39'S'#39' and d.fechasal > c.fech' +
        'a ) )'
      'group by a.codigo, b.salede, c.tipocte')
    Left = 504
    Top = 425
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_exist: TUpdateSQL
    Left = 194
    Top = 343
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 444
    Top = 341
    object borraren: TAction
      Caption = 'Eliminar'
      ImageIndex = 17
      OnExecute = borrarenExecute
    end
    object primer_artic: TAction
      Caption = 'Primero'
      ImageIndex = 5
      ShortCut = 49232
      OnExecute = primer_articExecute
    end
    object anter_artic: TAction
      Caption = 'Anterior'
      ImageIndex = 6
      ShortCut = 49217
      OnExecute = anter_articExecute
    end
    object sigte_artic: TAction
      Caption = 'Siguiente'
      ImageIndex = 8
      ShortCut = 49235
      OnExecute = sigte_articExecute
    end
    object ultimo_artic: TAction
      Caption = 'Ultimo'
      ImageIndex = 7
      ShortCut = 49237
      OnExecute = ultimo_articExecute
    end
  end
  object qry_formapago: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select idcrdcon, descri from inv_credcon where tipo = :TIPORELVT' +
        'AS'
      'order by idcrdcon')
    Left = 261
    Top = 355
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPORELVTAS'
        ParamType = ptUnknown
      end>
  end
  object dts_formapago: TDataSource
    DataSet = qry_formapago
    Left = 261
    Top = 384
  end
end
