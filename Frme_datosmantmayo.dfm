object Frame_datosmantmayo: TFrame_datosmantmayo
  Left = 0
  Top = 0
  Width = 601
  Height = 533
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 601
    Height = 361
    Align = alTop
    Caption = 'Datos Generales'
    TabOrder = 0
    object Label1: TLabel
      Left = 57
      Top = 29
      Width = 33
      Height = 13
      Caption = '&Código'
      FocusControl = edt_codvnd
    end
    object Label2: TLabel
      Left = 53
      Top = 51
      Width = 37
      Height = 13
      Caption = '&Nombre'
      FocusControl = edt_nombre
    end
    object Label12: TLabel
      Left = 28
      Top = 75
      Width = 62
      Height = 13
      Caption = 'Cont.Nombre'
    end
    object Label3: TLabel
      Left = 22
      Top = 98
      Width = 68
      Height = 13
      Caption = 'Calle y Czmtos'
    end
    object Label7: TLabel
      Left = 43
      Top = 170
      Width = 47
      Height = 13
      Caption = 'P&oblación'
    end
    object Label10: TLabel
      Left = 60
      Top = 190
      Width = 30
      Height = 13
      Caption = '&R.F.C.'
      FocusControl = edt_rfc
    end
    object Label4: TLabel
      Left = 48
      Top = 214
      Width = 42
      Height = 13
      Caption = '&Teléfono'
      FocusControl = edt_tel
    end
    object Label6: TLabel
      Left = 274
      Top = 216
      Width = 63
      Height = 13
      Caption = '% Descuento'
      FocusControl = edt_pdsc
    end
    object Label15: TLabel
      Left = 315
      Top = 190
      Width = 21
      Height = 13
      Caption = 'Tipo'
    end
    object Label16: TLabel
      Left = 307
      Top = 287
      Width = 30
      Height = 13
      Caption = 'Status'
      FocusControl = edt_pdsc
    end
    object Label17: TLabel
      Left = 18
      Top = 238
      Width = 73
      Height = 13
      Caption = 'Metodo Pago 1'
    end
    object Label18: TLabel
      Left = 282
      Top = 240
      Width = 54
      Height = 13
      Caption = 'N.Cuenta 1'
      FocusControl = edt_numcta
      Visible = False
    end
    object Label19: TLabel
      Left = 49
      Top = 122
      Width = 41
      Height = 13
      Caption = 'N.Predio'
    end
    object Label20: TLabel
      Left = 55
      Top = 146
      Width = 35
      Height = 13
      Caption = 'Colonia'
    end
    object Label21: TLabel
      Left = 288
      Top = 123
      Width = 51
      Height = 13
      Caption = 'Cod.Postal'
    end
    object lbl_email: TLabel
      Left = 65
      Top = 287
      Width = 25
      Height = 13
      Caption = 'Email'
    end
    object Label22: TLabel
      Left = 304
      Top = 171
      Width = 33
      Height = 13
      Caption = 'Estado'
    end
    object Label24: TLabel
      Left = 18
      Top = 262
      Width = 73
      Height = 13
      Caption = 'Metodo Pago 2'
    end
    object Label25: TLabel
      Left = 282
      Top = 264
      Width = 54
      Height = 13
      Caption = 'N.Cuenta 2'
      FocusControl = edt_numcta2
      Visible = False
    end
    object Label13: TLabel
      Left = 17
      Top = 311
      Width = 72
      Height = 13
      Caption = 'Régimen Fiscal'
    end
    object edt_codvnd: TEdit
      Left = 95
      Top = 25
      Width = 47
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 0
      OnKeyDown = edt_codvndKeyDown
    end
    object edt_nombre: TEdit
      Left = 95
      Top = 48
      Width = 401
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 1
    end
    object edt_nombre2: TEdit
      Left = 95
      Top = 71
      Width = 401
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 2
    end
    object edt_rfc: TEdit
      Left = 95
      Top = 189
      Width = 161
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 15
      TabOrder = 8
    end
    object edt_tel: TEdit
      Left = 95
      Top = 212
      Width = 161
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 10
    end
    object edt_pdsc: TdxCurrencyEdit
      Left = 343
      Top = 212
      Width = 154
      TabOrder = 11
      Alignment = taRightJustify
      DecimalPlaces = 3
      DisplayFormat = '0.000'
      StoredValues = 1
    end
    object edt_numcta: TEdit
      Left = 343
      Top = 236
      Width = 154
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 13
      Visible = False
    end
    object lkcmb_ciudad: TDBLookupComboBox
      Left = 95
      Top = 167
      Width = 161
      Height = 21
      DropDownWidth = 200
      KeyField = 'NUMERO'
      ListField = 'NOMBRE'
      ListSource = dts_ciudades
      TabOrder = 7
    end
    object lkcmb_tipomay: TDBLookupComboBox
      Left = 343
      Top = 189
      Width = 154
      Height = 21
      DropDownWidth = 200
      KeyField = 'idtipomay'
      ListField = 'descri'
      ListSource = dts_invtipomay
      TabOrder = 9
    end
    object cmb_status: TComboBox
      Left = 343
      Top = 284
      Width = 154
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 16
      Items.Strings = (
        'Alta'
        'Baja')
    end
    object edt_direc: TEdit
      Left = 95
      Top = 95
      Width = 401
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 50
      TabOrder = 3
    end
    object edt_numpred: TEdit
      Left = 95
      Top = 119
      Width = 150
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 50
      TabOrder = 4
      OnKeyDown = edt_codvndKeyDown
    end
    object edt_codpost: TEdit
      Left = 345
      Top = 119
      Width = 150
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 50
      TabOrder = 5
      OnKeyDown = edt_codvndKeyDown
    end
    object edt_colonia: TEdit
      Left = 95
      Top = 143
      Width = 401
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 50
      TabOrder = 6
    end
    object edt_email: TEdit
      Left = 95
      Top = 284
      Width = 161
      Height = 21
      TabOrder = 15
    end
    object db_estado: TDBEdit
      Left = 343
      Top = 167
      Width = 154
      Height = 21
      DataField = 'estado'
      DataSource = dts_ciudades
      TabOrder = 17
    end
    object lkcmb_metodopago: TDBLookupComboBox
      Left = 95
      Top = 236
      Width = 161
      Height = 21
      DropDownWidth = 300
      KeyField = 'IDTIPAGO'
      ListField = 'descri'
      ListSource = dts_mediospago
      TabOrder = 12
    end
    object lkcmb_metodopago2: TDBLookupComboBox
      Left = 95
      Top = 260
      Width = 161
      Height = 21
      DropDownWidth = 300
      KeyField = 'IDTIPAGO'
      ListField = 'descri'
      ListSource = dts_mediopago2
      TabOrder = 14
    end
    object edt_numcta2: TEdit
      Left = 343
      Top = 260
      Width = 154
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 18
      Visible = False
    end
    object lkcmb_regimen: TDBLookupComboBox
      Left = 95
      Top = 307
      Width = 402
      Height = 21
      KeyField = 'idregimen'
      ListField = 'DESCRITOT'
      ListSource = dts_regimen
      TabOrder = 19
    end
  end
  object pge_telefonos: TPageControl
    Left = 0
    Top = 361
    Width = 601
    Height = 172
    ActivePage = tbs_datospagare
    Align = alClient
    TabOrder = 1
    OnChange = pge_telefonosChange
    object tbs_datospagare: TTabSheet
      Caption = 'Datos Pagaré'
      object Label5: TLabel
        Left = 24
        Top = 12
        Width = 37
        Height = 13
        Caption = 'Nombre'
      end
      object Label8: TLabel
        Left = 16
        Top = 34
        Width = 45
        Height = 13
        Caption = 'Dirección'
      end
      object Label11: TLabel
        Left = 16
        Top = 58
        Width = 45
        Height = 13
        Caption = 'Dirección'
      end
      object Label9: TLabel
        Left = 14
        Top = 82
        Width = 47
        Height = 13
        Caption = 'Población'
      end
      object edt_nompag: TEdit
        Left = 66
        Top = 9
        Width = 401
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 0
      end
      object edt_dirpag: TEdit
        Left = 66
        Top = 31
        Width = 401
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 1
      end
      object edt_dirpag2: TEdit
        Left = 66
        Top = 55
        Width = 401
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 2
      end
      object lkcmb_ciudad2: TDBLookupComboBox
        Left = 67
        Top = 79
        Width = 401
        Height = 21
        DropDownWidth = 200
        KeyField = 'NOMBRE'
        ListField = 'NOMBRE'
        ListSource = dts_ciudades
        TabOrder = 3
      end
    end
    object tbs_telefonos: TTabSheet
      Caption = 'Teléfonos'
      ImageIndex = 1
      object dbgrd_telefonos: TdxDBGrid
        Left = 89
        Top = 0
        Width = 504
        Height = 144
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDRELAC'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        OnKeyDown = dbgrd_telefonosKeyDown
        DataSource = dts_telefonos
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks, edgoUseLocate]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        object dbgrd_telefonosTIPOTEL: TdxDBGridMaskColumn
          Caption = 'Telefono De'
          Width = 101
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TIPOTEL'
        end
        object dbgrd_telefonosNUMTEL: TdxDBGridMaskColumn
          Caption = 'Numero'
          Width = 205
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TELFAX'
        end
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 89
        Height = 144
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 1
        object BitBtn2: TBitBtn
          Left = 6
          Top = 72
          Width = 75
          Height = 25
          Action = elimina_tel
          Caption = 'Eliminar'
          TabOrder = 0
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
        object BitBtn1: TBitBtn
          Left = 6
          Top = 32
          Width = 75
          Height = 25
          Action = agregar_tel
          Caption = 'Agregar'
          TabOrder = 1
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
      end
    end
    object tbs_emailes: TTabSheet
      Caption = 'Correos'
      ImageIndex = 2
      object dbgrd_emailes: TdxDBGrid
        Left = 89
        Top = 0
        Width = 504
        Height = 144
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDRELAC'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        OnKeyDown = dbgrd_telefonosKeyDown
        DataSource = dts_emailes
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks, edgoUseLocate]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        object dbgrd_emailesCORREODE: TdxDBGridMaskColumn
          Caption = 'Correo De'
          Width = 101
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TIPOTEL'
        end
        object dbgrd_emailesCORREO: TdxDBGridMaskColumn
          Caption = 'Correo'
          Width = 205
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TELFAX'
        end
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 89
        Height = 144
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 1
        object BitBtn3: TBitBtn
          Left = 6
          Top = 56
          Width = 75
          Height = 25
          Action = elimina_tel
          Caption = 'Eliminar'
          TabOrder = 0
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
        object BitBtn4: TBitBtn
          Left = 6
          Top = 18
          Width = 75
          Height = 25
          Action = agregar_tel
          Caption = 'Agregar'
          TabOrder = 1
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
            FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
            0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
      end
    end
  end
  object qry_mayoris: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      
        'codigo, nombre, direc, ciu, rfc, tel, cargos, abonos, compraanu,' +
        ' comprames, pdsc,'
      
        'ultmov, status, cia, nompag1, nompag2, dirpag1, dirpag2, ciupag,' +
        ' nombre2, tipo'
      'from mayoris'
      'where codigo = :CODIGO and cia = :CIA')
    UpdateObject = uqry_mayoris
    Left = 464
    Top = 40
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
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 400
    Top = 320
    object nuevo: TAction
      Caption = '&Nuevo'
      ImageIndex = 0
      ShortCut = 16462
    end
    object modifica: TAction
      Caption = '&Modifica'
      Hint = 'Modifica'
      ImageIndex = 1
      ShortCut = 16461
    end
    object borra: TAction
      Caption = 'Borra'
      Hint = 'Borra'
      ImageIndex = 2
      ShortCut = 16450
    end
    object grabar: TAction
      Caption = 'Grabar'
      Enabled = False
      ImageIndex = 9
      ShortCut = 16455
    end
    object cancelar: TAction
      Caption = 'Cancelar'
      Enabled = False
      ImageIndex = 11
      ShortCut = 16460
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = 'C&lose'
      ImageIndex = 3
    end
    object primero: TAction
      Caption = 'Primero'
      Hint = 'Selecciona al Primer Mayorista'
      ImageIndex = 5
      ShortCut = 49232
    end
    object anterior: TAction
      Caption = 'anterior'
      Hint = 'Selecciona al Anterior Mayorista'
      ImageIndex = 6
      ShortCut = 49217
    end
    object siguiente: TAction
      Caption = 'siguiente'
      Hint = 'Selecciona al Siguiente Mayorista'
      ImageIndex = 8
      ShortCut = 49235
    end
    object ultimo: TAction
      Caption = 'ultimo'
      Hint = 'Selecciona al Ultimo Mayorista'
      ImageIndex = 7
      ShortCut = 49237
    end
    object elimina_tel: TAction
      Caption = 'Eliminar'
      ImageIndex = 17
      OnExecute = elimina_telExecute
    end
    object agregar_tel: TAction
      Caption = 'Agregar'
      ImageIndex = 13
      OnExecute = agregar_telExecute
    end
  end
  object qry_telefonos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.idrelac, a.idmayoris, a.mayoris, a.idtiporel, a.iddato1' +
        ', a.iddato2, a.cia,'
      'b.descri as tipotel, c.telfax'
      'from may_relac a join may_tipostel b on a.iddato1 = b.idtipotel'
      'join telfax c on a.iddato2 = c.idtel'
      
        'where a.mayoris = :MAYORIS and a.idtiporel = :IDTIPOREL and a.ci' +
        'a = :CIA'
      'order by tipotel'
      '')
    UpdateObject = uqry_telefonos
    Left = 515
    Top = 143
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IDTIPOREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_telefonos: TDataSource
    AutoEdit = False
    DataSet = qry_telefonos
    Left = 514
    Top = 114
  end
  object uqry_mayoris: TUpdateSQL
    ModifySQL.Strings = (
      'update mayoris'
      'set'
      '  CODIGO = :CODIGO,'
      '  NOMBRE = :NOMBRE,'
      '  DIREC = :DIREC,'
      '  CIU = :CIU,'
      '  RFC = :RFC,'
      '  TEL = :TEL,'
      '  CARGOS = :CARGOS,'
      '  ABONOS = :ABONOS,'
      '  COMPRAANU = :COMPRAANU,'
      '  COMPRAMES = :COMPRAMES,'
      '  PDSC = :PDSC,'
      '  ULTMOV = :ULTMOV,'
      '  STATUS = :STATUS,'
      '  CIA = :CIA,'
      '  NOMPAG1 = :NOMPAG1,'
      '  NOMPAG2 = :NOMPAG2,'
      '  DIRPAG1 = :DIRPAG1,'
      '  DIRPAG2 = :DIRPAG2,'
      '  CIUPAG = :CIUPAG,'
      '  NOMBRE2 = :NOMBRE2'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into mayoris'
      
        '  (CODIGO, NOMBRE, DIREC, CIU, RFC, TEL, CARGOS, ABONOS, COMPRAA' +
        'NU, '
      'COMPRAMES, '
      
        '   PDSC, ULTMOV, STATUS, CIA, NOMPAG1, NOMPAG2, DIRPAG1, DIRPAG2' +
        ', '
      'CIUPAG, '
      '   NOMBRE2)'
      'values'
      
        '  (:CODIGO, :NOMBRE, :DIREC, :CIU, :RFC, :TEL, :CARGOS, :ABONOS,' +
        ' '
      ':COMPRAANU, '
      
        '   :COMPRAMES, :PDSC, :ULTMOV, :STATUS, :CIA, :NOMPAG1, :NOMPAG2' +
        ', '
      ':DIRPAG1, '
      '   :DIRPAG2, :CIUPAG, :NOMBRE2)')
    DeleteSQL.Strings = (
      'delete from mayoris'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  CIA = :OLD_CIA')
    Left = 465
    Top = 70
  end
  object qry_tipostel: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idtipotel, descri from may_tipostel')
    Left = 545
    Top = 115
  end
  object qry_ciudades: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.nombre, a.numero, c.nombre as estado'
      'from poblacs a'
      'join car_relpobs b on a.numero = b.iddato1'
      'join car_estados c on b.iddato2 = c.idestado'
      'where b.tiporel = 2'
      'order by a.nombre'
      '')
    Left = 512
    Top = 40
  end
  object dts_ciudades: TDataSource
    DataSet = qry_ciudades
    Left = 512
    Top = 72
  end
  object uqry_telefonos: TUpdateSQL
    ModifySQL.Strings = (
      'update may_relac'
      'set'
      '  IDRELAC = :IDRELAC,'
      '  IDMAYORIS = :IDMAYORIS,'
      '  MAYORIS = :MAYORIS,'
      '  IDTIPOREL = :IDTIPOREL,'
      '  IDDATO1 = :IDDATO1,'
      '  IDDATO2 = :IDDATO2,'
      '  CIA = :CIA'
      'where'
      '  IDRELAC = :OLD_IDRELAC')
    InsertSQL.Strings = (
      'insert into may_relac'
      
        '  (IDRELAC, IDMAYORIS, MAYORIS, IDTIPOREL, IDDATO1, IDDATO2, CIA' +
        ')'
      'values'
      
        '  (:IDRELAC, :IDMAYORIS, :MAYORIS, :IDTIPOREL, :IDDATO1, :IDDATO' +
        '2, :CIA)')
    DeleteSQL.Strings = (
      'delete from may_relac'
      'where'
      '  IDRELAC = :OLD_IDRELAC')
    Left = 513
    Top = 171
  end
  object qry_invtipomay: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_tipomayoris where cia = :CIA order by tipomay')
    Left = 544
    Top = 40
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_invtipomay: TDataSource
    DataSet = qry_invtipomay
    Left = 544
    Top = 72
  end
  object qry_datospago: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.idrelac, a.idmayoris, a.mayoris, a.idtiporel, a.iddato1' +
        ','
      'a.iddato2, a.cia,'
      'b.concep as tipopago, c.concep as numcta'
      'from may_relac a join inv_conceps b on a.iddato1 = b.idconcep'
      'join inv_conceps c on a.iddato2 = c.idconcep'
      
        'where a.mayoris = :MAYORIS and a.idtiporel = :IDTIPOREL and a.ci' +
        'a = :CIA'
      '')
    UpdateObject = uqry_datospago
    Left = 547
    Top = 143
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IDTIPOREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_datospago: TUpdateSQL
    ModifySQL.Strings = (
      'update may_relac'
      'set'
      '  IDRELAC = :IDRELAC,'
      '  IDMAYORIS = :IDMAYORIS,'
      '  MAYORIS = :MAYORIS,'
      '  IDTIPOREL = :IDTIPOREL,'
      '  IDDATO1 = :IDDATO1,'
      '  IDDATO2 = :IDDATO2,'
      '  CIA = :CIA'
      'where'
      '  IDRELAC = :OLD_IDRELAC')
    InsertSQL.Strings = (
      'insert into may_relac'
      
        '  (IDRELAC, IDMAYORIS, MAYORIS, IDTIPOREL, IDDATO1, IDDATO2, CIA' +
        ')'
      'values'
      
        '  (:IDRELAC, :IDMAYORIS, :MAYORIS, :IDTIPOREL, :IDDATO1, :IDDATO' +
        '2, :CIA)')
    DeleteSQL.Strings = (
      'delete from may_relac'
      'where'
      '  IDRELAC = :OLD_IDRELAC')
    Left = 545
    Top = 171
  end
  object qry_mediospago: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'idtipago,'
      'clave,'
      'descri,'
      'orden,'
      'activo,'
      'complem'
      'from car_tipagocfdi'
      'where activo = :ACTIVO'
      'order by orden, clave'
      '')
    Left = 512
    Top = 288
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ACTIVO'
        ParamType = ptUnknown
      end>
  end
  object dts_mediospago: TDataSource
    DataSet = qry_mediospago
    Left = 512
    Top = 320
  end
  object qry_mediopago2: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'idtipago,'
      'clave,'
      'descri,'
      'orden,'
      'activo,'
      'complem'
      'from car_tipagocfdi'
      'where activo = :ACTIVO'
      'order by orden, clave'
      '')
    Left = 544
    Top = 288
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ACTIVO'
        ParamType = ptUnknown
      end>
  end
  object dts_mediopago2: TDataSource
    DataSet = qry_mediopago2
    Left = 544
    Top = 320
  end
  object dts_emailes: TDataSource
    AutoEdit = False
    DataSet = qry_emailes
    Left = 514
    Top = 202
  end
  object qry_emailes: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.idrelac, a.idmayoris, a.mayoris, a.idtiporel, a.iddato1' +
        ', a.iddato2, a.cia,'
      'b.descri as tipotel, c.telfax'
      'from may_relac a join may_tipostel b on a.iddato1 = b.idtipotel'
      'join telfax c on a.iddato2 = c.idtel'
      
        'where a.mayoris = :MAYORIS and a.idtiporel = :IDTIPOREL and a.ci' +
        'a = :CIA'
      'order by tipotel '
      ' '
      ' ')
    UpdateObject = uqry_emailes
    Left = 515
    Top = 231
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IDTIPOREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_emailes: TUpdateSQL
    ModifySQL.Strings = (
      'update may_relac'
      'set'
      '  IDRELAC = :IDRELAC,'
      '  IDMAYORIS = :IDMAYORIS,'
      '  MAYORIS = :MAYORIS,'
      '  IDTIPOREL = :IDTIPOREL,'
      '  IDDATO1 = :IDDATO1,'
      '  IDDATO2 = :IDDATO2,'
      '  CIA = :CIA'
      'where'
      '  IDRELAC = :OLD_IDRELAC')
    InsertSQL.Strings = (
      'insert into may_relac'
      
        '  (IDRELAC, IDMAYORIS, MAYORIS, IDTIPOREL, IDDATO1, IDDATO2, CIA' +
        ')'
      'values'
      
        '  (:IDRELAC, :IDMAYORIS, :MAYORIS, :IDTIPOREL, :IDDATO1, :IDDATO' +
        '2, :CIA)')
    DeleteSQL.Strings = (
      'delete from may_relac'
      'where'
      '  IDRELAC = :OLD_IDRELAC')
    Left = 513
    Top = 259
  end
  object qry_regimen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idregimen, codigo,  descri,'
      
        'cast ( (codigo || '#39' - '#39' || descri ) as varchar(120)) as descrito' +
        't'
      'from inv_regimenfiscal'
      'where status = :ACTIVO'
      'order by codigo'
      ' ')
    Left = 547
    Top = 200
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ACTIVO'
        ParamType = ptUnknown
      end>
  end
  object dts_regimen: TDataSource
    DataSet = qry_regimen
    Left = 547
    Top = 232
  end
end
